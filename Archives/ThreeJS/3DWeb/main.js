import './style.css'

import * as THREE from 'three';
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls';

const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
const renderer = new THREE.WebGLRenderer({
  canvas: document.querySelector('#bg'),
});

renderer.setPixelRatio(window.devicePixelRatio);
renderer.setSize(window.innerWidth, window.innerHeight);
camera.position.setZ(30); 


// torus geometry
// const geometry = new THREE.TorusGeometry(10, 3, 16, 100);
// const material = new THREE.MeshStandardMaterial({
//   color:  0x455AA4, wireframe: false,
// });
// const torus = new THREE.Mesh(geometry, material);

// scene.add(torus);

// box geometry
// const geometry = new THREE.BoxGeometry(15, 15, 15);
// const material = new THREE.MeshBasicMaterial( {color: 0x8e45a4 , wireframe: false} );
// const box = new THREE.Mesh( geometry, material );
// scene.add(box);

const pointLight = new THREE.PointLight(0xffffff);
pointLight.position.set(50, 50, 50);

const ambientLight = new THREE.AmbientLight(0xffffff);
scene.add(pointLight);

const texture = new THREE.TextureLoader().load('./img/img1.jpg');
const aks = new THREE.Mesh( 
  new THREE.BoxGeometry(13, 13, 13),
  new THREE.MeshBasicMaterial({map: texture})
)

scene.add(aks);
// const lightHelper = new THREE.PointLightHelper(pointLight); 
// const gridHelper = new THREE.GridHelper(200, 50); 
// scene.add(gridHelper);

const controls = new OrbitControls(camera, renderer.domElement);

function animate() {
  requestAnimationFrame(animate);
  aks.rotation.x += 0.01;
  aks.rotation.y += 0.005;
  // aks.rotation.z += 0.01;
  renderer.render(scene, camera);
}

animate();

const spaceTextures = new THREE.TextureLoader().load('./img/spaceimg.jpg'); 
scene.background = spaceTextures;

function addStars() {
  const starGeometry = new THREE.SphereGeometry(0.25, 24, 24);
  const starMaterial = new THREE.MeshStandardMaterial({color: 0xffffff});
  const star = new THREE.Mesh(starGeometry, starMaterial);

  const [x, y, z] = Array(3).fill().map(() => THREE.MathUtils.randFloatSpread(100));
  star.position.set(x, y, z);
  scene.add(star);
}

Array(200).fill().forEach(addStars);
