
    jQuery(function(){
            jQuery('select').selectmenu();
    });

                
                
   jQuery(document).ready(function(){
    var winWid=jQuery(window).width();
    if(winWid<481){
        jQuery('table').parent('div').css('overflow-x','scroll');
    }
    //
    
    
//    jQuery('span > .ui-selectmenu-dropdown').live("click",function(){
//        
//        var newArr = new Array();
//    maxHeight1=0;
//jQuery('.ui-selectmenu-menu > ul').each(function() {
//            var aH=newArr.push(jQuery(this).outerHeight());
//        //    alert(aH);
//        });
//         maxHeight1 = Math.max.apply(Math,newArr); 
//        
//        
//       var nW= jQuery('').ech;
//        alert(nW);
//        alert(winWid);
//        
//        if(winWid < nW){
//            
//            
//            alert(5)
//            
//        }
//        
//        
//    });
//    
    
    });
