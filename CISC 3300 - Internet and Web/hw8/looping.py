#!/usr/bin/env python3
print("Content-Type: text/html\n")

html = """<!DOCTYPE html>
<html>
<head>
<title>Python Looping</title>
<style>
th { background-color: blue; color: white; }
table { border-collapse: collapse; width: 200px; }
th, td { border: 1px solid black; padding: 8px; text-align: center; }
</style>
</head>
<body>
<table>
<tr><th>LOOPING</th></tr>"""

for i in range(1, 101):
    html += f"<tr><td>{i}</td></tr>"

html += """</table>
</body>
</html>"""

print(html)
