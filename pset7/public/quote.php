<?php

    // configuration
    require("../includes/config.php");
     
    if($_SERVER["REQUEST_METHOD"] == "POST") { 
        if( empty($_POST["symbol"] )  ) {
             apologize("Invlid / empty stock request" );
        }
        else { 
            //return stock as an associateive array with keys as "symbol" , "name" , "price"
            $stock = lookup($_POST["symbol"]) ;
            
            //print
            //number formatting to format to 2 decimal places
            print(  "  1 share of { $stock["name"]} costs { number_format ( float $stock["price"] [, int $decimals = 2 ] )} . \n  "  );
            
        }
    }
?>