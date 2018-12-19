<?php include "../inc/dbinfo.inc"; ?>
<html>
<body>

<?php

  /* Connect to MySQL and select the database. Information retrieved from "dbinfo.inc */
  $connection = mysqli_connect(DB_SERVER, DB_USERNAME, DB_PASSWORD);

  if (mysqli_connect_errno()) echo "Failed to connect to MySQL: " . mysqli_connect_error();

  $database = mysqli_select_db($connection, DB_DATABASE);

?>

<!-- Display table data. -->
<h1> EQUIPMENT BORROWED TABLE </h1>
<table border="1" cellpadding="2" cellspacing="2">
  <tr>
    <td>Student ID</td>
    <td>Equipment Serial Number</td>
    <td>Checked Out</td>
	<td>Due Date</td>
	<td>Returned (1=true , 0=false)</td>
  </tr>

<?php

if(isset($_POST['EquipmentBorrowedSubmit'])){
	
	$query = "SELECT * FROM EQUIPMENT_BORROWED WHERE eb_sid = \"" . $_POST['studentID'] . "\";";
	$result = mysqli_query($connection, $query); 

	
	while($query_data = mysqli_fetch_array($result)) {
	  echo "<tr>";
	  echo "<td>",$query_data[0], "</td>",
		"<td>",$query_data[1], "</td>",
		"<td>",$query_data[2], "</td>",
		"<td>",$query_data[3], "</td>",
		"<td>",$query_data[4], "</td>";
	  
	  echo "</tr>";
	}
}

?>

</table>

</body>
</html>