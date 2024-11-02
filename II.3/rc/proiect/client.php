<?php

$s = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
$c = socket_connect($s, "INSERT_IP", INSERT_PORT);

if ($c === false) {
    die("Eroare la conectare: " . socket_strerror(socket_last_error()));
}

echo "Bun venit la Wordle!\n";
echo "Ghicește un cuvânt de 5 litere.\n";

$maxAttempts = 6;
$attempts = 0;

while ($attempts < $maxAttempts) {
    // Citire guess de la utilizator
    echo "Încercarea " . ($attempts + 1) . ": ";
    $guess = trim(fgets(STDIN));

    // Validare lungime
    if (strlen($guess) !== 5) {
        echo "Cuvântul trebuie să aibă 5 litere!\n";
        continue;
    }

    // Trimite guess-ul la server
    socket_write($s, $guess . "\n");

    // Primește răspunsul de la server
    $response = socket_read($s, 1024);
    $result = json_decode($response, true);

    // Afișează rezultatul
    foreach ($result['letters'] as $letterInfo) {
        $letter = $letterInfo['letter'];
        $status = $letterInfo['status'];

        // Colorare bazată pe status
        switch ($status) {
            case 'green':
                echo "\033[42m $letter \033[0m"; // Fundal verde
                break;
            case 'yellow':
                echo "\033[43m $letter \033[0m"; // Fundal galben
                break;
            case 'gray':
                echo "\033[47m $letter \033[0m"; // Fundal gri
                break;
        }
    }
    echo "\n";

    $attempts++;

    // Verifică condiții de final
    if (isset($result['won']) && $result['won'] === true) {
        echo "Felicitări! Ai ghicit cuvântul!\n";
        break;
    }

    if (isset($result['message'])) {
        echo $result['message'] . "\n";
        break;
    }
}

// Închide socket-ul
socket_close($s);
?>