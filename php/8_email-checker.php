<html>
    <head><title>8</title></head>
    <body>
        <form method="POST">
            Enter email ID: <input type="text" name="email"> <br>
            <input type="submit" name="submit" value="submit">
        </form>

        <?php
            if(isset($_POST['submit'])) {
                if(isset($_POST['email'])) {
                    $email = $_POST['email'];
                    $email_array = explode('@', $email);

                    if($email_array[0] == "" || $email_array[1] == "") {
                        echo "Invalid email ID! <br>";
                        return;
                    } else echo "Valid email ID! <br>";
                    $domain_name = $email_array[1];

                    $connection = mysqli_connect("localhost", "root", "password", "practicals")
                                    or die("Couldn't connect to database!");
                    $query = "SELECT * FROM domains WHERE domainname = '$domain_name'";

                    $result = mysqli_query($connection, $query);

                    if(mysqli_num_rows($result) == 1) {
                        echo "Domain name '$domain_name' exists.<br>";
                    } else echo "No domain name '$domain_name' found!<br>";
                }
            }
        ?>
    </body>
</html>