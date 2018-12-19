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

if(isset($_POST['DeleteEquipmentSubmit'])){
	
	$query = "DELETE FROM EQUIPMENT WHERE e_serialNumber = \"" . $_POST['serialNumber'] . "\";";
	$result = mysqli_query($connection, $query); 

	$query = "DELETE FROM EQUIPMENT_BORROWED WHERE eb_serialNumber = \"" . $_POST['serialNumber'] . "\";";
	$result = mysqli_query($connection, $query); 
	
	echo "<h1> EQUIPMENT DELETED SUCCESSFULLY <h1>";
}

?>

</table>

</body>
</html>