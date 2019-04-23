<html>
    <head><title>3</title></head>
    <body>
        <form method="POST">
            Enter string1: <input type="text" name="str1"> <br>
            Enter your choice: <br>
            <input type="radio" name="choice" value="1"> Remove whitespaces <br>
            <input type="radio" name="choice" value="2"> Check if a string contains another string 2 <input type="text" name="str2"> <br>
            <input type="radio" name="choice" value="3"> Check if a string is all lowercase <br>
            <input type="radio" name="choice" value="4"> Replace the first 'the' with 'that' <br>
            <input type="submit" name="submit" value="submit">
        </form>

        <?php
            if(isset($_POST['submit'])) {
                if(isset($_POST['choice'])) {
                    $choice = $_POST['choice'];
                    $str1 = $_POST['str1'];
                    $str2 = $_POST['str2'];
                    switch($choice) {
                        case '1' : echo str_replace(' ', '', $str1); break;
                        case '2' : if(strpos($str1, $str2) !== false) {
                            echo "'$str1' contains '$str2' at position " . strpos($str1, $str2);
                        } else echo "'$str1' doesn't contain '$str2'"; 
                        break;
                        case '3' : if(preg_match('/[^a-z]/', $str1)) {
                            echo "'$str1' isn't all lowercase!";
                        } else echo "'$str1' is all lowercase.";
                        break;
                        case '4' : echo preg_replace('/the/', 'that', $str1, 1); break;
                    }                    
                }
            }
        ?>
    </body>
</html>