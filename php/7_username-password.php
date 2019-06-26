<html>
    <head><title>7</title></head>
    <body>
        <form method="POST">
            Enter username: <input type="text" name="username"> <br>
            Enter password: <input type="password" name="password"> <br>
            <input type="submit" name="submit" value="submit">
        </form>

        <?php
            if(isset($_POST['submit'])) {
                if(isset($_POST['username']) && isset($_POST['password'])) {
                    $username = $_POST['username'];
                    $password = $_POST['password'];

                    $connection = mysqli_connect("localhost", "root", "password", "practicals")
                                    or die("Couldn't connect to database!");
                    $query = "SELECT * FROM users WHERE username='$username'";

                    $result = mysqli_query($connection, $query);

                    if(mysqli_num_rows($result) == 1) {
                        echo "Username exists.<br>";
                        if(mysqli_fetch_assoc($result)['password'] == $password) {
                            echo "Welcome $username! <br>";
                        } else echo "Invalid password! <br>";
                    } else echo "No such username found!<br>";
                }
            }
        ?>
    </body>
</html>