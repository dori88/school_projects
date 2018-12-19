<?php include "../inc/dbinfo.inc"; ?>
<html>
<body>

<?php

  /* Connect to MySQL and select the database. Information retrieved from "dbinfo.inc */
  $connection = mysqli_connect(DB_SERVER, DB_USERNAME, DB_PASSWORD);

  if (mysqli_connect_errno()) echo "Failed to connect to MySQL: " . mysqli_connect_error();

  $database = mysqli_select_db($connection, DB_DATABASE);

?>

<!-- Insert row in student table-->
<?php

if(isset($_POST['UpdateStudentSubmit'])){
	
	$query = "INSERT INTO STUDENT VALUES (\"" . $_POST['studentID'] . "\" , \"" . $_POST['studentName'] . "\" , \"" . $_POST['phone'] . "\");";
	//echo $query;
	$result = mysqli_query($connection, $query); 
	
	/*$query = "SELECT * FROM STUDENT WHERE s_id = \"" . $_POST['studentID'] . "\";";
	//echo $query;
	$result = mysqli_query($connection, $query); 
	
	while($query_data = mysqli_fetch_array($result)) {
	  echo "<table border=\"1\" cellpadding=\"2\" cellspacing=\"2\">";
	  echo "<tr>";
	  echo "<td>",$query_data[0], "</td>",
			"<td>",$query_data[1], "</td>",
			"<td>",$query_data[2], "</td>";
	  
	  echo "</tr>";
	  echo "</table>";
	}*/
	
	$query = "INSERT INTO STUDENT_ADDRESS VALUES (\"" . $_POST['studentID'] . "\" , " . $_POST['houseNumber'] . 
	" , \"" . $_POST['streetName'] . "\" , \"" . $_POST['city'] . "\" , \"" . $_POST['state'] ."\" , \"" . $_POST['zip'] ."\");";
	//echo $query;
	$result = mysqli_query($connection, $query); 
	
	
	/*$query = "SELECT * FROM STUDENT_ADDRESS WHERE sa_sid = \"" . $_POST['studentID'] . "\";";
	//echo $query;
	$result = mysqli_query($connection, $query);
	
	while($query_data = mysqli_fetch_array($result)) {
	  echo "<table border=\"1\" cellpadding=\"2\" cellspacing=\"2\">";
	  echo "<tr>";
	  echo "<td>",$query_data[0], "</td>",
			"<td>",$query_data[1], "</td>",
			"<td>",$query_data[2], "</td>",
			"<td>",$query_data[3], "</td>",
			"<td>",$query_data[4], "</td>",
			"<td>",$query_data[5], "</td>";
	  
	  echo "</tr>";
	  echo "</table>";
	}	*/
	
	
	echo "<h1> STUDENT ADDED SUCCESSFULLY <h1>";
	
}

?>

</body>
</html>