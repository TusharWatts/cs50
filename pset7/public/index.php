<?php

    // configuration
    require("../includes/config.php"); 
    
    //retreive id of the "logged-in" user
    $id = $_SESSION["id"];
    
    //retreive info about the shares the user possess
    $rows = query("SELECT * FROM portfolio WHERE id = $id");
    
    foreach ($rows as $row) {
        $stock = lookup($row["symbol"]); 
        if ($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"],
            ]; 
        }
    }
    

    // render portfolio
    render("portfolio.php", ["title" => "Portfolio"]);

?>
