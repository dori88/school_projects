<?php include "../inc/dbinfo.inc"; ?>
<html>
<head>
<style>
body{
	background-color: #A8E0FF
}
</style>
</head>
<body>

<img src="ARCBanner.png" alt="ARC Banner" height="162" width="800" align="middle">

<h1 style="color:green;">ARC DATABASE</h1>
<br>

<?php

  /* Connect to MySQL and select the database. Information retrieved from "dbinfo.inc */
  $connection = mysqli_connect(DB_SERVER, DB_USERNAME, DB_PASSWORD);

  if (mysqli_connect_errno()) echo "Failed to connect to MySQL: " . mysqli_connect_error();

  $database = mysqli_select_db($connection, DB_DATABASE);

?>


<form action="NumberOfStudents.php" method="POST">
	<h2 style="color:blue;">Number of Students Registered</h2>
	<input type="submit" name="NumberOfStudentsSubmit" value="Get Number Of Students">
</form>

<br>
<hr>
<br>


<form action="Department.php" method="POST">
	<h2 style="color:blue;">Look Up Department Phone Number</h2>
	<input type="radio" name="departmentName" value="Game" > Game Department <br>
	<input type="radio" name="departmentName" value="Camp"> Camp Department <br>
	<input type="radio" name="departmentName" value="Fitness"> Fitness Department <br>
	<input type="radio" name="departmentName" value="Intramurals"> Intramurals Department <br>
	<input type="radio" name="departmentName" value="Sport"> Sport Department <br><br>
	<input type="submit" name="DepartmentSubmit" value="Get Department Phone Number">
</form>

<br>
<hr>
<br>

<form action="AddEquipment.php" method="POST">
	<h2 style="color:blue;">Add Equipment to ARC</h2>
	Department <br>
	<input type="radio" name="departmentName" value="Game"> Game Department <br>
	<input type="radio" name="departmentName" value="Camp"> Camp Department <br>
	<input type="radio" name="departmentName" value="Fitness"> Fitness Department <br>
	<input type="radio" name="departmentName" value="Intramurals"> Intramurals Department <br>
	<input type="radio" name="departmentName" value="Sport"> Sport Department <br><br>
	Serial Number <input type="textbox" name="serialNumber" maxlength="4"><br>
	Equipment Name <input type="textbox" name="equipmentName"> <br><br>
	Type <br>
	<input type="radio" name="type" value="Camping"> Camping <br>
	<input type="radio" name="type" value="Sporting"> Sporting <br>
	<input type="radio" name="type" value="Gaming"> Gaming <br> <br>
	Year Bought <input type="textbox" name="year" maxlength="4"> <br><br>
	<input type="submit" name="AddEquipmentSubmit" value="Add New Equipment">
</form>

<br>
<hr>
<br>

<form action="AddStudent.php" method="POST">
	<h2 style="color:blue;">Add New Student to ARC</h2>
	Student ID <input type="textbox" name="studentID"><br>
	Name (First Last) <input type="textbox" name="studentName"><br>
	Phone Number <input type="textbox" name="phone" value="xxx-xxx-xxxx"> <br>
	House Number <input type="textbox" name="houseNumber"> <br>
	Street Name <input type="textbox" name="streetName"> <br>
	City <input type="textbox" name="city"> <br>
	State <input type="textbox" name="state"> <br>
	Zip <input type="textbox" name="zip"> <br> <br>
	<input type="submit" name="UpdateStudentSubmit" value="Add New Student">
</form>

<br>
<hr>
<br>

<form action="DeleteStudent.php" method="POST">
	<h2 style="color:blue;">Delete Student From ARC</h2>
	Student ID <br> <input type="textbox" name="studentID"><br><br>
	<input type="submit" name="DeleteStudentSubmit" value="Delete Student">
</form>

<br>
<hr>
<br>

<form action="DeleteEquipment.php" method="POST">
	<h2 style="color:blue;">Delete Equipment From ARC</h2>
	Serial Number <br> <input type="textbox" name="serialNumber" maxlength="4"><br><br>
	<input type="submit" name="DeleteEquipmentSubmit" value="Delete Equipment">
</form>


<br>
<hr>
<br>

<form action="CheckOutEquipment.php" method="POST">
	<h2 style="color:blue;">Check Out Equipment</h2>
	Student ID <input type="textbox" name="studentID"><br>
	Serial Number <input type="textbox" name="serialNumber" maxlength="4"> <br><br>
	<input type="submit" name="CheckOutEquipmentSubmit" value="Check Out Equipment">
</form>

<br>
<hr>
<br>


<form action="Student.php" method="POST">
	<h2 style="color:blue;">Look Up All Information About Student</h2>
	Student ID <br> <input type="textbox" name="studentID"><br><br>
	<input type="submit" name="StudentSubmit" value="Get Student Information">
</form>

<br>
<hr>
<br>

<form action="ActivityParticipate.php" method="POST">
	<h2 style="color:blue;">Activities Participated by Student</h2>
	Student ID <br> <input type="textbox" name="studentID"><br><br>
	<input type="submit" name="ActivityParticipateSubmit" value="Get Equipment Borrowed">
</form>

<br>
<hr>
<br>

<form action="EquipmentBorrowed.php" method="POST">
	<h2 style="color:blue;">Equipment Borrowed by Student</h2>
	Student ID <br> <input type="textbox" name="studentID"><br><br>
	<input type="submit" name="EquipmentBorrowedSubmit" value="Get Equipment Borrowed">
</form>


<br>
<hr>
<br>

<form action="Equipment.php" method="POST">
	<h2 style="color:blue;">Look Up Equipment</h2>
	<p> Look up by Department or Equipment Serial Number</p>
	<p> Department: </p>
	<input type="radio" name="departmentName" value="Game"> Game Department <br>
	<input type="radio" name="departmentName" value="Camp"> Camp Department <br>
	<input type="radio" name="departmentName" value="Fitness"> Fitness Department <br>
	<input type="radio" name="departmentName" value="Intramurals"> Intramurals Department <br>
	<input type="radio" name="departmentName" value="Sport"> Sport Department <br><br>
	<input type="submit" name="EquipmentDepartmentSubmit" value="Get Equipment">
	
	<p>  <i>OR</i>  </p>
	<p> Equipment Serial: </p>
	<input type="textbox" name="equipmentSerial"><br><br>
	<input type="submit" name="EquipmentSerialSubmit" value="Get Equipment">
	
	
	
</form>



<br>
<hr>
<br>

<form action="Activity.php" method="POST">
	<h2 style="color:blue;">Look Up Activities</h2>
	<p> Department: </p>
	<input type="radio" name="departmentName" value="Game"> Game Department <br>
	<input type="radio" name="departmentName" value="Camp"> Camp Department <br>
	<input type="radio" name="departmentName" value="Fitness"> Fitness Department <br>
	<input type="radio" name="departmentName" value="Intramurals"> Intramurals Department <br>
	<input type="radio" name="departmentName" value="Sport"> Sport Department <br><br>
	<input type="submit" name="ActivitySubmit" value="Get Activities">
</form>


<br>
<hr>
<br>

<form action="RoomsReserved.php" method="POST">
	<h2 style="color:blue;">Look Up Rooms Reserved</h2>
	<p> <i>Enter BOTH Department Name and Room Number</i> </p>
	<p> Department: </p>
	<input type="radio" name="departmentName" value="Game"> Game Department <br>
	<input type="radio" name="departmentName" value="Camp"> Camp Department <br>
	<input type="radio" name="departmentName" value="Fitness"> Fitness Department <br>
	<input type="radio" name="departmentName" value="Intramurals"> Intramurals Department <br>
	<input type="radio" name="departmentName" value="Sport"> Sport Department <br><br>
	Room Number <br> <input type="textbox" name="roomNumber"><br><br>
	<input type="submit" name="RoomSubmit" value="Rooms Reserved">
</form>






 





</table>

<!-- Clean up. -->
<?php

  mysqli_free_result($result);
  mysqli_close($connection);

?>

</body>
</html>

