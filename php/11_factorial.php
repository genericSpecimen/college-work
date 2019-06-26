<!DOCTYPE html>
<html>
<head>
    <title>Factorial calculator</title>
</head>
<body>
    <form method = "POST">
        Enter a number to calculate its factorial: <br>
        <input type = "number" name = "n">
        <input type = "submit" name = "submit">
    </form>

    <?php
        function factorial($n) {
            if($n <= 0) return 1;
            $fact = 1;
            for($i = $n; $i >= 1; $i--) {
                $fact *= $i;
            }
            return $fact;
        }

        if(isset($_POST['submit'])) {
            if(isset($_POST['n'])) {
                $n = $_POST['n'];
                echo "Factorial of " . $n . " is: " . factorial($n) . "<br>"; 
            }
        }
    ?>
    
</body>
</html>

