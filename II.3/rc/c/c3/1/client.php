<?php
$s=socket_create(AF_INET,SOCK_STREAM,0);
socket_connect($s,"127.0.0.1",6969);
?>
