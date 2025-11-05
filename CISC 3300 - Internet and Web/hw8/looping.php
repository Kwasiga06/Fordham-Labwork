<!DOCTYPE html>
<html>
<head>
<title>PHP Looping</title>
<style>
th { background-color: blue; color: white; }
table { border-collapse: collapse; width: 200px; }
th, td { border: 1px solid black; padding: 8px; text-align: center; }
</style>
</head>
<body>
<table>
<tr><th>LOOPING</th></tr>
<?php
for ($i = 1; $i <= 100; $i++) {
    echo "<tr><td>$i</td></tr>";
}
?>
</table>
</body>
</html>
