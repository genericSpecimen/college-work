<!DOCTYPE html>
<html>
<head>
    <title>Sum of first n odd numbers</title>
</head>
<body>
    <form method = "POST">
        Print sum of first <input type = "number" name = "n"> odd numbers. <br>
        <input type = "submit" name = "submit">
    </form>

    <?php
        if(isset($_POST['submit'])) {
            if(isset($_POST['n'])) {
                $n = $_POST['n'];
                $sum = 0;
                $num1 = 1;
                for($i=0;$i<$n;$i++) {
                    //echo $num1 . ", ";
                    $sum += $num1;
                    $num1 += 2;
                }
                echo "Sum of first " . $n . " odd numbers: " . $sum;
            }
        }
    ?>
    
</body>
</html>