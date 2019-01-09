let El_data = [];


class Position{
    constructor(element, postion){
        this.element = element;
        this.postion = postion;
    }
}

$(document).ready(function() {
    $('.elements').draggable({
        revert: true,
        containment: 'document'
    });
    $('.slot').droppable({
        drop: function(event, ui) {
      
            let something = new Position(ui, this);
            El_data.push(something);
            console.log("El_data elements number: " + El_data.length);
      
            // console.log(something.element);
            console.log(something.postion);
      
            $(this)
            ui.draggable.detach().appendTo($(this));
            //ddClass('highlighted')
        }
    });
    $('button').click(function(){
        dataCheck();
    });
});

function dataCheck() {
    console.log("boole");
  
    //$('.slot').find('.elements').attr('id') = El_data;
    console.log(El_data);
};




function assignEl() {
  
};