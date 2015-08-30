(function ($) {
  Drupal.behaviors.fase_help = {
    attach: function (context, settings) {
      $('.page-user-feneko-screens-orders .help').click(function() {
        $('.page-user-feneko-screens-orders .help-text').slideToggle();

        return false;
      });
    }
  }
}(jQuery));

