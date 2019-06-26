<?php
    $title = "Insert";
    require_once('header.php');
?>

        <div class="main">
            <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
                <div class="container">
                <h1>Insert a record.</h1>
                <p>Please enter the following details.</p>
                <hr>

                <label for="field1"><b>Field 1</b></label> <br>
                <input type="text" placeholder="Enter field 1" name="field1" required> <br>

                <label for="field2"><b>Field 2</b></label> <br>
                <input type="text" placeholder="Enter field 2" name="field2"> <br>

                <input type="submit" value="Insert record" name="submit" class="loginbtn">
            </div>
        </form>
        </div>
    </body>
</html>
