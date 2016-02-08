$(document).ready(function(){
  $(".fancybox").fancybox({
    helpers : {
      overlay : {
        css : {
          'background' : 'rgba(58, 42, 45, 0.95)'
        }
      }
    },

    padding    : 0,
    margin     : 5,
    nextEffect : 'fade',
    prevEffect : 'none',
    autoCenter : false

  });
});