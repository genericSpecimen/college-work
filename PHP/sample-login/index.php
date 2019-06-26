<?php
    require_once('modules/login.php');
    if(isset($_SESSION['username'])) {
        header("Location: modules/homepage.php");
    }
?>

<html>
<head>
<title>Welcome</title>
<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
    <div class="container">
        <h1>Log in</h1>
        <p>Please enter the following details.</p>
        <hr>

        <label for="username"><b>Username</b></label> <br>
        <input type="text" placeholder="Enter username" name="username" required> <br>

        <label for="password"><b>Password</b></label> <br>
        <input type="password" placeholder="Enter Password" name="password" required> <br>
        <input type="submit" value="Log in" name="submit" class="loginbtn">
    </div>
</form>
<div class="error">
  <span>
    <p> <?php echo $error; ?> </p>
  </span>
</div>

</body>
</html>



