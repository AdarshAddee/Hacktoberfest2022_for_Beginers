<?php
	$owner_email = $_POST["owner_email"];
	$headers = 'From:' . $_POST["email"];
	$subject = 'A message from your site visitor ' . $_POST["name"];
	$messageBody = "";
	
	if($_POST['name']!='nope'){
		$messageBody .= '<p>Visitor: ' . $_POST["name"] . '</p>' . "\n";
		$messageBody .= '<br>' . "\n";
	}
	if($_POST['email']!='nope'){
		$messageBody .= '<p>Email Address: ' . $_POST['email'] . '</p>' . "\n";
		$messageBody .= '<br>' . "\n";
	}else{
		$headers = '';
	}
	if($_POST['state']!='nope'){		
		$messageBody .= '<p>State: ' . $_POST['state'] . '</p>' . "\n";
		$messageBody .= '<br>' . "\n";
	}
	if($_POST['phone']!='nope'){		
		$messageBody .= '<p>Phone Number: ' . $_POST['phone'] . '</p>' . "\n";
		$messageBody .= '<br>' . "\n";
	}	
	if($_POST['fax']!='nope'){		
		$messageBody .= '<p>Fax Number: ' . $_POST['fax'] . '</p>' . "\n";
		$messageBody .= '<br>' . "\n";
	}
	if($_POST['message']!='nope'){
		$messageBody .= '<p>Message: ' . $_POST['message'] . '</p>' . "\n";
	}
	
	if($_POST["stripHTML"] == 'true'){
		$messageBody = strip_tags($messageBody);
	}
	
	try{
		if(!mail($owner_email, $subject, $messageBody, $headers)){
			throw new Exception('mail failed');
		}else{
			echo 'mail sent';
		}
	}catch(Exception $e){
		echo $e->getMessage() ."\n";
	}
?>