<?php include "../inc/dbinfo.inc"; ?>
<html>
<body>

<?php

  /* Connect to MySQL and select the database. Information retrieved from "dbinfo.inc */
  $connection = mysqli_connect(DB_SERVER, DB_USERNAME, DB_PASSWORD);

  if (mysqli_connect_errno()) echo "Failed to connect to MySQL: " . mysqli_connect_error();

  $database = mysqli_select_db($connection, DB_DATABASE);

?>

<!-- Insert row in Equipment table-->
<?php

if(isset($_POST['AddEquipmentSubmit'])){
	
	$query = "INSERT INTO EQUIPMENT VALUES (\"" . $_POST['departmentName'] . "\" , \"" . $_POST['serialNumber'] . 
	"\" , \"" . $_POST['equipmentName'] . "\" , \"" . $_POST['type'] . "\" , " . $_POST['year'] . ");";
	//echo $query;
	$result = mysqli_query($connection, $query); 
	
	echo "<h1> EQUIPMENT ADDED SUCCESSFULLY <h1>";
	
}

?>

</body>
</html>