<?php
	function print_array($arr) {
		foreach ($arr as $a) {
			echo $a . ", ";
		}
	}
	$arr = array(10,210,1,10,6);
	sort($arr);
	print_array($arr);
?>
