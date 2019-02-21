

window.onload = function(){
    imgLoaction("container","box");

    //虚拟待加载文件
    var imgData = {"data":[{"src":"0.jpg"},{"src":"1.jpg"},{"src":"2.jpg"},{"src":"3.jpg"}]};
    window.onscroll = function () {
        if(checkFlag()){
            var cparent = document.getElementById("container");
            for(var i=0;i<imgData.data.length;i++){                         //动态创建网页
                var ccontent  = document.createElement("div");
                ccontent.className = "box";
                cparent.appendChild(ccontent);
                var boximg = document.createElement("div");
                boximg.className = "box_img";
                ccontent.appendChild(boximg);
                var img = document.createElement("img");
                img.src = "photos/" + imgData.data[i].src;
                boximg.appendChild(img);
            }
            imgLoaction("container","box");     //再次调用瀑布流效果
        }

    }
}


//下拉加载效果
function  checkFlag() {
    var cparent = document.getElementById("container"); //父类容器
    var ccontent = getChildElement(cparent,"box");  //box盒子对象集合
    var lastContentHeight = ccontent[ccontent.length - 1].offsetTop;  // 最后一张照片距顶部距离
    var scrolltop = document.documentElement.scrollTop || document.body.scrollTop;  //滑动距离
    var pageHeight = document.documentElement.clientHeight || document.body.clientHeight;   //页面距顶距离
    if(lastContentHeight < (scrolltop + pageHeight)){}
        return true;    //允许加载
}


//瀑布流效果
function imgLoaction(parent,content){
    //将parent下多有的content全部取出
    var cparent = document.getElementById(parent);
    var ccontent = getChildElement(cparent,content);    // box盒子对象集合
    
    var imgWidth = ccontent[0].offsetWidth;             //img宽度
    var num = Math.floor(document.documentElement.clientWidth / imgWidth); //根据当前窗口决定 横排摆放数量
    cparent.style.cssText = "width:" + imgWidth*num + "px;margin:0 auto";  //css修改样式

    var BoxHeightArr = [];
    for(var i=0;i<ccontent.length;i++){     //处理图片集合
        if(i<num){
            BoxHeightArr[i] = ccontent[i].offsetHeight;
        }else{
            var minheight = Math.min.apply(null,BoxHeightArr);  //最小高度
            var minIndex = getminheightLocation(BoxHeightArr,minheight);    //最小高度索引
            //开始摆放
            ccontent[i].style.position = "absolute";    //绝对布局
            ccontent[i].style.top = minheight + "px";   //上下
            ccontent[i].style.left = ccontent[minIndex].offsetLeft + "px";  //左右

            BoxHeightArr[minIndex] = BoxHeightArr[minIndex] + ccontent[i].offsetHeight;         //更新插入后的盒子高度
        }
    }
}

function getminheightLocation(BoxHeightArr,minheight){
    for(var i in BoxHeightArr){
        if(BoxHeightArr[i] == minheight){
            return i;       //返回最矮照片的位置
        }
    }
}

function getChildElement(parent,content){
    var contentArr = [];
    var allcontent = parent.getElementsByTagName("*");
    for(var i=0;i<allcontent.length;i++){
        if(allcontent[i].className == content){
            contentArr.push(allcontent[i]);
        }
    }
    return contentArr;
}