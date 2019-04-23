<!DOCTYPE html>
<html>
<head>
    <title>Fibonacci Series</title>
</head>
<body>
    <form method = "POST">
        Print the first  <input type = "number" name = "n"> Fibonacci numbers.<br>
        <input type = "submit" name = "submit">
    </form>

    <?php
        function fib($i) {
            if($i == 0 || $i == 1) return $i;
            else return fib($i-1) + fib($i-2);
        }


        if(isset($_POST['submit'])) {
            if(isset($_POST['n'])) {
                $n = $_POST['n'];
                for($i=0;$i<$n;$i++) echo fib($i) . ", ";
            }
        }
    ?>
    
</body>
</html>