<!DOCTYPE html>
<html>
<head>
    <title>First n even numbers</title>
</head>
<body>
    <form method = "POST">
        Print the first <input type = "number" name = "n"> even numbers.<br>
        <input type = "submit" name = "submit">
    </form>

    <?php
        if(isset($_POST['submit'])) {
            if(isset($_POST['n'])) {
                $n = $_POST['n'];
                $num1 = 0;
                for($i=0;$i<$n;$i++) {
                    echo $num1 . ", ";
                    $num1 += 2;
                }
            }
        }
    ?>
    
</body>
</html>