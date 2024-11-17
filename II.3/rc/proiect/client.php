<?php

$s = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
$c = socket_connect($s, "localhost", 12345);

if ($c === false) {
    die("Connection error: " . socket_strerror(socket_last_error()));
}

echo "🎉 Welcome to Wordle! 🎉\n";
echo "Objective: Guess the secret 5-letter word.\n\n";
echo "🔍 Here are the rules:\n";
echo "- You have 6 attempts to find the correct word.\n";
echo "- After each guess, you'll get visual clues:\n";
echo "  🟩 Green: The letter is correct and in the right position!\n";
echo "  🟨 Yellow: The letter is correct but in the wrong position.\n";
echo "  ⬜ Gray: The letter is not in the secret word.\n\n";
echo "Good luck, and have fun guessing! 🔠💡\n";

$maxAttempts = 6;
$attempts = 0;

while ($attempts < $maxAttempts) {
    // Read user guess
    echo "Attempt " . ($attempts + 1) . ": ";
    $guess = trim(fgets(STDIN));

    // Validate length
    if (strlen($guess) !== 5) {
        echo "The word must be 5 letters long!\n";
        continue;
    }

    // Send guess to server
    socket_write($s, $guess . "\n");

    // Receive response from server
    $response = socket_read($s, 1024);
    $result = json_decode($response, true);

    // Display the result
    foreach ($result['letters'] as $letterInfo) {
        $letter = $letterInfo['letter'];
        $status = $letterInfo['status'];

        // Color based on status
        switch ($status) {
            case 'green':
                echo "\033[42m $letter \033[0m"; // Green background
                break;
            case 'yellow':
                echo "\033[43m $letter \033[0m"; // Yellow background
                break;
            case 'gray':
                echo "\033[47m $letter \033[0m"; // Gray background
                break;
        }
    }
    echo "\n";

    $attempts++;

    // Check end conditions
    if (isset($result['won']) && $result['won'] === true) {
        echo "Congratulations! You've guessed the word!\n";
        break;
    }

    if (isset($result['message'])) {
        echo $result['message'] . "\n";
        break;
    }
}

// Close the socket
socket_close($s);
?>
