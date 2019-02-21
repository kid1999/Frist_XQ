"""Views_2 URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/2.1/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path
from cala import views as cala_views

urlpatterns = [
    path('admin/', admin.site.urls),
    # path('add/',cala_views.add,name='add'),
    # 旧网站 跳向新网站
    path('add/<int:a>/<int:b>/',cala_views.old_to_new_add),
    path('add2/<int:a>/<int:b>/',cala_views.add2,name='add2'),
    path('',cala_views.index),
]
