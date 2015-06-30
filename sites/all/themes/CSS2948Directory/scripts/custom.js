 //var sel=  jQuery('select').is('[multiple]');
    jQuery(function() {
        
        
/*        
        
    jQuery('select').each(function() {
        
        jQuery(this).attr('style','');
         jQuery(this).css('display','block').css('min-width',100);
        var sel = jQuery(this).is('[multiple]');
        if (!sel) {
            jQuery(this).selectmenu();
             jQuery(this).css('display','none');
        }
    })
});
*/

jQuery(document).ajaxComplete(function() {
    jQuery('select').each(function() {
         jQuery(this).attr('style','');
          jQuery(this).css('display','block');
        var sel = jQuery(this).is('[multiple]');
        if (!sel) {
            jQuery(this).selectmenu();
             jQuery(this).css('display','none');
        }
    })
    
    //
    
    
     var winWid=jQuery(window).width();
    if(winWid<481){
      //  alert(9);
        jQuery('table').parent('div').css('overflow-x','scroll');
    }
    
    
    
});
                
   jQuery(document).ready(function(){
    var winWid=jQuery(window).width();
    if(winWid<481){
      //  alert(9);
        jQuery('table').parent('div').css('overflow-x','scroll');
    }
    //
    
      jQuery('.field-item').each(function() {
                if(jQuery(this).children().length <= 0){
                    jQuery(this).addClass('font-maintain').css('font-size','1.4em');
                }else{
                      jQuery(this).addClass('font-no');
                }
            });
    
    
    
    
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
