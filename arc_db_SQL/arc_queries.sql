-- number of soccer balls for loan
SELECT e_serialNumber
FROM EQUIPMENT
WHERE e_name = "Soccer Ball" AND e_serialNumber IN (SELECT e.e_serialNumber
FROM EQUIPMENT as e
WHERE e.e_serialNumber NOT IN (SELECT eb_serialNumber FROM EQUIPMENT_BORROWED)
UNION ALL
(SELECT eb_serialNumber FROM EQUIPMENT_BORROWED WHERE eb_returned = 1));


--  Display number of items checked out
SELECT COUNT(*) as Num_of_items_on_loan
FROM EQUIPMENT_BORROWED
WHERE eb_returned = 0;

-- Display all students who have items checked out
SELECT eb.eb_sid as SID, s.s_name as Student_name, eb.eb_serialNumber as Equipment_serialNumber, e.e_name as Equipment_name
FROM EQUIPMENT_BORROWED as eb, EQUIPMENT as e, STUDENT as s
WHERE eb.eb_returned = 0 AND eb.eb_serialNumber = e.e_serialNumber AND eb.eb_sid = s.s_id;

-- Display all student who have items overdue
SELECT eb.eb_sid as SID, s.s_name as Student_name, eb.eb_serialNumber as Equipment_serialNumber, e.e_name as Equipment_name, eb.eb_dueDate as Due_date
FROM EQUIPMENT_BORROWED as eb, EQUIPMENT as e, STUDENT as s
WHERE eb.eb_returned = 0 AND eb.eb_dueDate < CURDATE() AND eb.eb_serialNumber = e.e_serialNumber AND eb.eb_sid = s.s_id
ORDER BY eb.eb_dueDate;

-- Display the number of participants in an Activity held by Camp Dept on April 22, 2018.
SELECT a.a_dname as Department, a.a_date as Date, a.a_name as Activity_name, COUNT(*) as Num_of_participants
FROM ACTIVITY as a, ACTIVITY_PARTICIPATE as ap
WHERE a.a_dname = "Camp" AND a.a_date = "2018-04-22" AND ap.ap_aid = a.a_id
GROUP BY a_name;

-- Display all student who have reserved a room on Feb 15, 2018
SELECT s.s_id as SID, s.s_name as Student_name, rr.rr_rnumber as Room_no, rr.rr_dname as Dept
FROM STUDENT as s, ROOM_RESERVE as rr
WHERE rr.rr_checkIn >= '2018-02-15 00:00:00' AND rr.rr_checkOut <= '2018-02-15 23:59:59' AND rr.rr_sid = s.s_id;

-- Update the address of student Jim Kim who has ID number “3333333”
UPDATE STUDENT as s
SET s.s_phone_num =  '425-321-3832'
WHERE s.s_id = '3333333';

-- Display detailed information of students who has signed up activity with activity ID “2222”
SELECT s.s_id as SID, s.s_name as Student_name, s.s_phone_num as Phone_no, sa.sa_houseNumber as House_no,
sa.sa_streetName as St_name, sa.sa_city as City, sa.sa_state as State, sa.sa_zip as Zip
FROM STUDENT as s, STUDENT_ADDRESS as sa, ACTIVITY_PARTICIPATE as ap
WHERE ap.ap_aid = 2222 AND ap.ap_sid = s.s_id AND s.s_id = sa.sa_sid;

-- Student “1111111” wants to check out soccer ball “8567”.
INSERT INTO EQUIPMENT_BORROWED(eb_sid, eb_serialNumber, eb_checkedOut, eb_dueDate,eb_returned)
VALUES ('1111111', '8547',  '2018-03-11', '2018-03-15', 0);

-- Student “2222222” wants to sign up for camping trip “2345”.
INSERT INTO ACTIVITY_PARTICIPATE(ap_sid, ap_aid)
VALUES ('2222222', '2345');

-- Student “2222222” wants to check out Monopoly game.
INSERT INTO EQUIPMENT_BORROWED(eb_sid, eb_serialNumber, eb_checkedOut, eb_dueDate,eb_returned)
VALUES ('2222222', (SELECT e_serialNumber FROM EQUIPMENT WHERE e_name = 'Monopoly'),  '2018-03-11', '2018-03-15', 0);

-- Student returns game with serialNumber ‘5678’.
DELETE FROM EQUIPMENT_BORROWED
WHERE eb_serialNumber = '5678';


