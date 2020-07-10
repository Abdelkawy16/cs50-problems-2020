function del(id)
{
    var r = confirm('Do you want to delete that note?!');
    if (r) {
      $('#'+id).remove();
    }
}