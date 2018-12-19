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

if(isset($_POST['CheckOutEquipmentSubmit'])){
	
	$date = date('Y-m-d');
	$nextWeek = date('Y-m-d', strtotime('+1 week'));
	//echo $date;
	//echo "<br>";
	//echo $nextWeek;
	
	$query = "INSERT INTO EQUIPMENT_BORROWED VALUES (\"" . $_POST['studentID'] .  "\" , \"" .  $_POST['serialNumber'] . "\" , \"" . $date . "\", \""  
	. $nextWeek . "\" , 0);";
	//echo $query;
	$result = mysqli_query($connection, $query); 

	echo "<h1> EQUIPMENT BORROWED SUCCESSFULLY <h1>";
}

?>

</table>

</body>
</html>