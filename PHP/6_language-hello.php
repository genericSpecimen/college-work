<html>
    <head><title>6</title></head>
    <body>
        <form method="POST">
            Select a language:    
            <select name="lang">
                <option value="English">English</option>
                <option value="Spanish">Spanish</option>
                <option value="French">French</option>
            </select>
            <input type="submit" name="submit" value="submit">
        </form>

        <?php
            if(isset($_POST['submit'])) {
                if(isset($_POST['lang'])) {
                    $lang = $_POST['lang'];
                    switch($lang) {
                        case "English": echo "Hello <br>"; break;
                        case "Spanish": echo "Hola <br>"; break;
                        case "French": echo "Bonjour <br>"; break;
                    }
                }
            }
        ?>
    </body>
</html>