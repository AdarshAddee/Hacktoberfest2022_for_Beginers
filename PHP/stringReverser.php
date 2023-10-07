<?php
$inputString = '';
$reversedString = '';

if (isset($_POST['submit'])) {
    $inputString = $_POST['string'];
    $reversedString = strrev($inputString);
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>String Reverser</title>
</head>
<body>
    <form action="stringReverser.php" method="POST">
        <input type="text" name="string" value="<?php echo htmlspecialchars($inputString); ?>">
        <input type="submit" name="submit" value="Reverse">
    </form>
    
    <?php if (!empty($reversedString)) { ?>
        <p>Reversed String: <?php echo htmlspecialchars($reversedString); ?></p>
    <?php } ?>
</body>
</html>
