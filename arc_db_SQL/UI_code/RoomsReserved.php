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
<h1> ROOM TABLE </h1>
<table border="1" cellpadding="2" cellspacing="2">
  <tr>
    <td>Student ID</td>
    <td>Department Name</td>
    <td>Room Number</td>
	<td>Check In</td>
	<td>Check Out</td>
  </tr>

<?php

if(isset($_POST['RoomSubmit'])){

	$query = "SELECT * FROM ROOM_RESERVE WHERE rr_dname = \"" . $_POST['departmentName'] . "\" AND rr_rnumber = \"" . $_POST['roomNumber'] . "\" ;";
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