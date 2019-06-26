<?php
    session_start();
    if(!isset($_SESSION['username'])) {
        exit('You are not logged in! Please login here:  <a href="index.php">Log in</a> ');
    }
?>
<!DOCTYPE html>
<html>
    <head>
        <title> <?php echo $title?> </title>
        <link rel="stylesheet" type="text/css" href="../style.css">
    </head>
    <body>
        <div class="navbar">
            <b>
            <a href="insert.php">Insert</a>
            <a href="update.php">Update</a>
            <a href="delete.php">Delete</a>
            <a href="logout.php">Log out</a>
            <a href="homepage.php"><?php echo $_SESSION['username']?></a>
            </b>
            <hr style="width: 100%">
        </div>