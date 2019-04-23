<html>
    <head>
        <title>9</title>
        <style>
        table, th, td {
            border: 1px solid black;
        }
        </style>
    </head>
    <body>
        <form method="POST">
            Enter Roll Number: <input type="text" name="rollno"> <br>
            Enter Name: <input type="text" name="name"> <br>
            <input type="submit" name="submit" value="submit">
        </form>

        <?php
            if(isset($_POST['submit'])) {
                if(isset($_POST['rollno']) && isset($_POST['name'])) {
                    $rollno = $_POST['rollno'];
                    $name = $_POST['name'];

                    $connection = mysqli_connect("localhost", "root", "password", "practicals")
                                 or die("Couldn't connect to database!");
                    $query = "SELECT *, (marks1 + marks2 + marks3)/3 AS avg FROM students WHERE rollno='$rollno' AND name='$name'";
                    //echo $query;

                    $result = mysqli_query($connection, $query);

                    if(mysqli_num_rows($result) == 1) {
                        echo "Record found!.<br>";
                        echo "<table>";
                        echo "<th>Roll no</th>";
                        echo "<th>Name</th>";
                        echo "<th>Marks1</th>";
                        echo "<th>Marks2</th>";
                        echo "<th>Marks3</th>";
                        echo "<th>Avg</th>";
                        echo "<th>Grade</th>";

                        echo "<tr>";
                        while($row = mysqli_fetch_assoc($result)) {
                            echo "<td>" . $row['rollno'] . "</td>";
                            echo "<td>" . $row['name'] . "</td>";
                            echo "<td>" . $row['marks1'] . "</td>";
                            echo "<td>" . $row['marks2'] . "</td>";
                            echo "<td>" . $row['marks3'] . "</td>";

                            $average = $row['avg'];
                            echo "<td>" . $average . "</td>";
                            
                            echo "<td>";
                            if($average >= 90) echo "A";
                            else if($average >= 80 && $average < 90) echo "B";
                            else if($average >= 70 && $average < 80) echo "C";
                            else if($average >= 60 && $average < 70) echo "D";
                            else if($average >= 50 && $average < 60) echo "E";
                            else if($average >= 40 && $average < 50) echo "F";
                            
                            echo "</td>";
                        }
                        echo "<tr>";
                        echo "</table>";
                    } else echo "No record found!<br>";
                    
                }
            }
        ?>
    </body>
</html>