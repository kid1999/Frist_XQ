"""myechartsite URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/1.11/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  url(r'^$', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  url(r'^$', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.conf.urls import url, include
    2. Add a URL to urlpatterns:  url(r'^blog/', include('blog.urls'))
"""
from django.conf.urls import url
from django.contrib import admin
from myfirstvis import views
from . import tmp

urlpatterns = [
    url(r'^admin/', admin.site.urls),
    url(r'^$',tmp.index),       #静态主页
    url(r'^map/',tmp.map),      #返回静态结果页
    #子网页返回
    url(r'^男女分布.html$',tmp.one),       #1
    url(r'^钦州学院大数据学生年龄分布.html$',tmp.two),       #2
    url(r'^钦州学院大数据童鞋分布geo.html$',tmp.three),       #3
    url(r'^大数据方向学生劣势科目.html$',tmp.four),       #4
    url(r'^社团参与率.html$',tmp.five),       #5
    url(r'^大学期盼.html$',tmp.six),       #6
    url(r'^大数据方向学生擅长科目.html$',tmp.seven),       #7
    url(r'^大数据同学分布map.html$',tmp.nine),       #9

    url(r'^3Dgraph$',views.index),  #返回动态3d页
    url(r'^geomap/',views.map),  #返回动态结果页
]
