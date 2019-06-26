<html>
    <head> <title>4</title> </head>
    <body>
        <form method="POST">
            Enter your birthdate in YYYY-MM-DD format: <input type="text" name="bdate">
            <input type="submit" name="submit" value="submit">
        </form>
        <?php
            if(isset($_POST['submit'])) {
                if(isset($_POST['bdate'])) {
                    $bdate = $_POST['bdate'];
                    echo "Your birth date: $bdate <br>";

                    $bdate = strtotime($bdate); // convert to unix timestamp

                    $today = strtotime("now");

                    // make the year same as current year
                    $fixed_bdate_str = date('Y', $today) . "-" . date('m', $bdate) . "-" . date('d', $bdate);;
                    
                    // create a DateTime object of fixed bdate
                    $fixed_bdate = date_create($fixed_bdate_str);

                    // and today
                    $today = date_create(date('Y-m-d', $today));

                    $diff = date_diff($today, $fixed_bdate);

                    echo "Days till next birthday: " . $diff->format("%R%a days");

                }
            }
        ?>
    </body>
</html>