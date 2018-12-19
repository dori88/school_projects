<?php include "../inc/dbinfo.inc"; ?>
<html>
<body>

<?php

  /* Connect to MySQL and select the database. Information retrieved from "dbinfo.inc */
  $connection = mysqli_connect(DB_SERVER, DB_USERNAME, DB_PASSWORD);

  if (mysqli_connect_errno()) echo "Failed to connect to MySQL: " . mysqli_connect_error();

  $database = mysqli_select_db($connection, DB_DATABASE);

?>

<?php

if(isset($_POST['DeleteStudentSubmit'])){
	
	$query = "DELETE FROM STUDENT WHERE s_id = \"" . $_POST['studentID'] . "\";";
	$result = mysqli_query($connection, $query); 
	
	$query = "DELETE FROM STUDENT_ADDRESS WHERE sa_id = \"" . $_POST['studentID'] . "\";";
	$result = mysqli_query($connection, $query); 
	
	$query = "DELETE FROM EQUIPMENT_BORROWED WHERE eb_sid = \"" . $_POST['studentID'] . "\";";
	$result = mysqli_query($connection, $query);
	
	$query = "DELETE FROM ROOM_RESERVE WHERE rr_sid = \"" . $_POST['studentID'] . "\";";
	$result = mysqli_query($connection, $query);
	
	$query = "DELETE FROM ACTIVITY_PARTICIPATE WHERE ap_sid = \"" . $_POST['studentID'] . "\";";
	$result = mysqli_query($connection, $query);

	echo "<h1> STUDENT DELETED SUCCESSFULLY <h1>";
}

?>

</table>

</body>
</html>