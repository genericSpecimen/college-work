<?php
    $color = array("white", "green", "red");
    foreach ($color as $c) {
        echo "$c, ";
    }
    sort($color);

    echo "<ul>";
    foreach($color as $c) {
        echo "<li>" . $c . "</li>";
    }
    echo "</ul>";
?>