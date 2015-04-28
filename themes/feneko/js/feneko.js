function getParameterByName(name) {
  name = name.replace(/[\[]/, "\\\[").replace(/[\]]/, "\\\]");
  var regexS = "[\\?&]" + name + "=([^&#]*)";
  var regex = new RegExp(regexS);
  var results = regex.exec(window.location.search);
  if(results == null) return "";
  else return decodeURIComponent(results[1].replace(/\+/g, " "));
}


(function ($) {
  /**
   * Main menu behavior
   **/
  Drupal.behaviors.main_menu = {
    attach: function (context, settings) {
    	$('#edit-submit,.form-submit').addClass('drukknopform');
  		$('#block-views-terms-block .taxonomy-term,#block-views-terms-block-1 .taxonomy-term').click(function(){
	  		window.location = $(this).find('a').attr('href');
		  });
		  $('.front [id*=block-views-terms-block] .taxonomy-term h3').hide();
		  $('.front [id*=block-views-terms-block] .taxonomy-term').hover(function(){
		  	$(this).find('h3').show();
		  },function(){
			  $(this).find('h3').hide();
		  });

      $('.node-product.node-teaser').click(function(){
			  var aurl = $(this).find('.field-name-title h2 a').attr('href');
			  console.log(aurl);
			  window.location = aurl;
		  });

		  var referrer_nid = getParameterByName('referrer');
		  var referrer_title = getParameterByName('referrer_title');
		  if(referrer_nid>0){
  			$('#edit-submitted-functie-waarvor-u-solliciteert').val(referrer_title);
			}
    }
  };
}(jQuery));

