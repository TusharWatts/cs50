

<?php

    // configuration
    require("../includes/config.php");
    
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // TODO
        //if password or confirmation password is empty, apologize
        if(  empty($_POST["password"])  ||  empty($_POST["confirmation"])  ) 
        {
            apologize("ERROR : Please enter your Password or Confirmation Password");
        }
        
        //if password and confirm password do not match
        if( $_POST["password"] != $_POST["confirmation"]  )
        {
            apologize("ERROR : Password and Confirmation Password do not match");
        }
        
        //if username is empty , apologize
        if( empty($_POST["username"]) ) 
        {
            apologize("ERROR : Please enter a valid username");
        }
        else  //else add the username
        {
            $result = query("INSERT IGNORE INTO users (username, hash, cash) VALUES(?, ?, 10000.0000)", $_POST["username"], password_hash($_POST["password"], PASSWORD_DEFAULT));
        
            if(result == false)
                apologize("ERROR : Duplicate username");
            else //find the ID 
            {
                $rows = query("SELECT LAST_INSERT_ID() AS id");
                $id = $rows[0]["id"];
                $_SESSION["id"]=$id;
                redirect("index.php");
            }
        }
           

    }

?>

