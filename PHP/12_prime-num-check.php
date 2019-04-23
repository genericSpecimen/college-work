<!DOCTYPE html>
<html>
<head>
    <title>Prime number checker</title>
</head>
<body>
    <form method = "POST">
        Enter a number to check if it is prime: <br>
        <input type = "number" name = "n">
        <input type = "submit" name = "submit">
    </form>

    <?php
        function is_prime($n) {
            if($n <= 1) {
                return false;
            }
            else {
                for($i = 2; $i <= floor(sqrt($n)); $i++) {
                    if($n % $i == 0) return false;
                }
            }
            return true;
        }

        if(isset($_POST['submit'])) {
            if(isset($_POST['n'])) {
                $n = $_POST['n'];
                if(is_prime($n)) {
                    echo $n . " is PRIME <br>"; 
                } else echo $n . " is NOT PRIME <br>";
            }
        }
    ?>
    
</body>
</html>