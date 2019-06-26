<html>
	<head> <title>1</title> </head>
	<body>
		<form method="POST">
			Enter a string: <input type="text" name="str">
			<input type="submit" name="submit" value="submit">
		</form>

		<?php
			if(isset($_POST['submit'])) {
				if(isset($_POST['str'])) {
					echo "Reversed string: " . strrev($_POST['str']);
				}
			}
		?>
	</body>
</html>
