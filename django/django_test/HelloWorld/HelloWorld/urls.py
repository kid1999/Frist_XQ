from django.conf.urls import url
from django.contrib import admin
from . import view,testdb,search,search2    #调用框架里的中间处理节点

urlpatterns = [
    url(r'^hello$',view.hello),
    url(r'^testdb$',testdb.testdb),
    url(r'^admin/', admin.site.urls),
    url(r'^search-form$',search.search_from),
    url(r'^search$',search.search),
    url(r'^search-post$',search2.search_post),
]
