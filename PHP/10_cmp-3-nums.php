<html>
    <head><title>10</title></head>
    <body>
        <form method="POST">
            Enter three numbers to compare them: <br>
            <input type="number" name="numbers[]">
            <input type="number" name="numbers[]">
            <input type="number" name="numbers[]"> <br>
            <input type="submit" name="submit" value="submit">
        </form>

        <?php
            function largest_num($num1, $num2, $num3) {
                $largest = $num1;
                if($num2 > $largest) $largest = $num2;
                if($num3 > $largest) $largest = $num3;
                return $largest;
            }
            if(isset($_POST['submit'])) {
                if(isset($_POST['numbers'])) {
                    $num1 = $_POST['numbers'][0];
                    $num2 = $_POST['numbers'][1];
                    $num3 = $_POST['numbers'][2];
                    echo "Largest number is: " . largest_num($num1, $num2, $num3);
                }
            }
        ?>
    </body>
</html>