<?php
    session_start();
    $error = '';

    if(isset($_POST['submit'])) {
        if( empty($_POST['username']) || empty($_POST['password']) ) {
            $error = "Username or password is empty!";
        } else {
            require_once('db.inc');
            $connection = new mysqli($servername, $db_username, $db_password, $db_name);
            // Check connection
            if ($conn->connect_error) {
                die("Connection failed: " . $conn->connect_error);
            }

            $username = htmlspecialchars($_POST['username']);
            $password = htmlspecialchars($_POST['password']);

            $username = $connection->real_escape_string($username);
            $password = $connection->real_escape_string($password);

            $query = "SELECT username, password FROM users WHERE username='$username' AND password='$password'";
            $result = $connection->query($query);
            if($result->num_rows == 1) {
                //echo "Welcome " , $username, "<br>";
                $_SESSION['username'] = $username;
                $_SESSION['logged_in'] = true;
                header("Location: homepage.php");
            } else {
                $error = "Invalid username or password!<br>";
            }

            $connection->close();
        }
    }
?>