<?php
    $title = "Home page";
    require_once('header.php');
?>

        <div class="main">
            <p>Welcome to your homepage, <b><?php echo $_SESSION['username']; ?></b>.</p>
            <p>Choose an option from the top menu bar.</p>
        </div> 
    </body>
</html>
