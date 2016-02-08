(function($) {
  $(document).ready(function() {
    var success = function() {
      $('#test-form').ajaxForm({
        target: '#form',
        success: success
      });
    };
    $('#test-link').click(function(event) {
      $.get(Drupal.settings.basePath + 'callback', function(data) {
        $('#form').html(data);
        Drupal.attachBehaviors('#test-form');
        success();
      });
      event.preventDefault();
    });
  });
})(jQuery);