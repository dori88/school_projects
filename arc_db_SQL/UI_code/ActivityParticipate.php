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
<h1> ACTIVITIES STUDENT IS PARTICIPATING IN </h1>
<table border="1" cellpadding="2" cellspacing="2">
  <tr>
    <td>Activity ID</td>
	<td>Departent Name</td>
	<td>Activity Name</td>
	<td>Activity ID</td>
	<td>Type</td>
	<td>Date</td>
  </tr>

<?php

if(isset($_POST['ActivityParticipateSubmit'])){
	
	$query = "SELECT ap_aid, a_dname, a_name, a_id, a_type, a_date FROM ACTIVITY_PARTICIPATE, ACTIVITY WHERE ap_aid = a_id AND ap_sid = \"" . $_POST['studentID'] . "\";";
	$result = mysqli_query($connection, $query); 

	
	while($query_data = mysqli_fetch_array($result)) {
	  echo "<tr>";
	  echo "<td>",$query_data[0], "</td>",
		"<td>",$query_data[1], "</td>",
		"<td>",$query_data[2], "</td>",
		"<td>",$query_data[3], "</td>",
		"<td>",$query_data[4], "</td>",
		"<td>",$query_data[5], "</td>";
	  
	  echo "</tr>";
	}	
	
}

?>

</table>


</body>
</html>