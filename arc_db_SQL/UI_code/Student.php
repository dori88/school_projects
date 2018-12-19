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
<h1> STUDENT CONTACT INFORMATION </h1>
<table border="1" cellpadding="2" cellspacing="2">
  <tr>
    <td>Name</td>
	<td>Phone Number</td>
	<td>House Number</td>
	<td>Street Name</td>
	<td>City</td>
	<td>State</td>
	<td>Zip</td>
  </tr>

<?php

if(isset($_POST['StudentSubmit'])){
	
	$query = "SELECT s_name, s_phone_num, sa_houseNumber, sa_streetName, sa_city, sa_state, sa_zip FROM STUDENT, STUDENT_ADDRESS WHERE s_id = sa_sid AND s_id = \"" . $_POST['studentID'] . "\";";
	$result = mysqli_query($connection, $query); 

	
	while($query_data = mysqli_fetch_array($result)) {
	  echo "<tr>";
	  echo "<td>",$query_data[0], "</td>",
		"<td>",$query_data[1], "</td>",
		"<td>",$query_data[2], "</td>",
		"<td>",$query_data[3], "</td>",
		"<td>",$query_data[4], "</td>",
		"<td>",$query_data[5], "</td>",
		"<td>",$query_data[6], "</td>";
	  
	  echo "</tr>";
	}
	
	
}

?>

</table>




<br>
<br>


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

if(isset($_POST['StudentSubmit'])){
	
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
	

	
	

<br>
<br>


<!-- Display table data. -->
<h1> EQUIPMENT BORROWED BY STUDENT </h1>
<table border="1" cellpadding="2" cellspacing="2">
  <tr>
    <td>Equipment Serial Number</td>
    <td>Checked Out</td>
	<td>Due Date</td>
	<td>Returned (1=true,0=false)</td>
  </tr>

<?php

if(isset($_POST['StudentSubmit'])){
	
	$query = "SELECT eb_serialNumber, eb_checkedOut, eb_dueDate, eb_returned FROM EQUIPMENT_BORROWED WHERE eb_sid = \"" . $_POST['studentID'] . "\";";
	$result = mysqli_query($connection, $query); 

	
	while($query_data = mysqli_fetch_array($result)) {
	  echo "<tr>";
	  echo "<td>",$query_data[0], "</td>",
		"<td>",$query_data[1], "</td>",
		"<td>",$query_data[2], "</td>",
		"<td>",$query_data[3], "</td>";
	  
	  echo "</tr>";
	}
}

?>

</table>	
	
	

	
<br>
<br>


<!-- Display table data. -->
<h1> ROOMS RESERVE BY STUDENT </h1>
<table border="1" cellpadding="2" cellspacing="2">
  <tr>
    <td>Department Name</td>
    <td>Room Number</td>
	<td>Check In</td>
	<td>Check Out</td>
  </tr>

<?php

if(isset($_POST['StudentSubmit'])){
	
	$query = "SELECT rr_dname, rr_rnumber, rr_checkIn, rr_checkOut FROM ROOM_RESERVE WHERE rr_sid = \"" . $_POST['studentID'] . "\";";
	$result = mysqli_query($connection, $query); 

	
	while($query_data = mysqli_fetch_array($result)) {
	  echo "<tr>";
	  echo "<td>",$query_data[0], "</td>",
		"<td>",$query_data[1], "</td>",
		"<td>",$query_data[2], "</td>",
		"<td>",$query_data[3], "</td>";
	  
	  echo "</tr>";
	}
}

?>

</table>	
	
	

</body>
</html>