<!DOCTYPE html>
<html>
<head>
    <title>Insert data in DB</title>
</head>
<body>
    <form method = "POST">
        Enter your name: <input type = "text" name = "name"> <br>
        Enter your address: <input type = "text" name = "address"> <br>
        <input type = "submit" name = "submit"> <br>
    </form>

    <?php
        if(isset($_POST['submit'])) {
            if(isset($_POST['name']) && isset($_POST['address'])) {
                $name = $_POST['name'];
                $address = $_POST['address'];
                // echo $name . "<br>" . $address . "<br>";

                $servername = "localhost";
                $username = "root";
                $password = "password";
                $dbname = "PHPPractical0";

                // Create connection
                $connection = mysqli_connect($servername, $username, $password, $dbname);

                // Check connection
                if (!$connection) {
                    die("Connection failed: " . mysqli_connect_error());
                }
                echo "Connected successfully! <br>";

                $query = "INSERT INTO People VALUES ('" . $name . "', '" . $address . "')";
                //echo $query;

                if (mysqli_query($connection, $query)) {
                    echo "New record created successfully";
                } else {
                    echo "Error: " . $query . "<br>" . mysqli_error($conn);
                }

                mysqli_close($connection); 
            }
        }
    ?>
</body>
</html>