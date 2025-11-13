<?php
function generateMultiplicationTable($rows, $cols) {
	$rows = max(1, (int)$rows);
	$cols = max(1, (int)$cols);

	echo '<style>
	.mult-table { border-collapse: collapse; margin: 12px 0; font-family: Arial, sans-serif; background-color: #fff; }
	.mult-table th, .mult-table td { border: 1px solid #000; padding: 6px 10px; text-align: center; background-color: #fff; }
	.mult-table th.header, .mult-table th.row-header { background-color: #007BFF; color: #fff; font-weight: bold; }
	.mult-table td.alt, .mult-table td.product { background-color: #fff; }
	</style>';

	echo "<table class=\"mult-table\">\n";

	echo "<thead>\n<tr>";
	echo "<th class=\"header\"></th>";

	for ($c = 1; $c <= $cols; $c++) {
		echo "<th class=\"header\">$c</th>";
	}
	echo "</tr>\n</thead>\n<tbody>\n";

	for ($r = 1; $r <= $rows; $r++) {
		echo "<tr>";
		echo "<th class=\"row-header\">$r</th>";

		$c = 1;
		while ($c <= $cols) {
			$product = $r * $c;
			$cellClass = (($r + $c) % 2 === 0) ? 'product' : 'alt';
			echo "<td class=\"$cellClass\">$product</td>";
			$c++;
		}

		echo "</tr>\n";
	}

	echo "</tbody>\n</table>\n";
}


echo "<!doctype html><html><head><meta charset='utf-8'><title>Multiplication Tables</title></head><body>";
echo "<h2>Multiplication Table 10 x 10</h2>";
generateMultiplicationTable(10, 10);

$maxRow = rand(1, 10);
$maxColumn = rand(1, 10);

echo "<h2>Random Multiplication Table {$maxRow} x {$maxColumn}</h2>";
generateMultiplicationTable($maxRow, $maxColumn);

echo "</body></html>";
?>