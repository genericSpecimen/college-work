<!DOCTYPE html>
<html>
<head>
    <title>Palindrome Checker</title>
</head>
<body>
    <form method = "POST">
        Enter a string to check if it's a palindrome. <br>
        <input type = "text" name = "str"> <br>
        <input type = "submit" name = "submit">
    </form>

    <?php
        if(isset($_POST['submit'])) {
            if(isset($_POST['str'])) {
                $s = $_POST['str'];
                //remove whitespaces
                $s = str_replace(' ', '', $s);
                //remove special characters
                $s = preg_replace('/[^A-Za-z0-9]/', '', $s);
                //convert to lowercase
                $s = strtolower($s);

                if($s == strrev($s)) {
                    echo $s . " is a Palindrome";
                } else echo $s . " is not a Palindrome.";
            }
        }
    ?>
    
</body>
</html>