// Mengambil data sensor secara berkala dari ESP
setInterval(() => {
  fetch('/getData')
    .then((response) => response.json())
    .then((data) => {
      document.getElementById('temperature').innerText = data.temperature;
      document.getElementById('humidity').innerText = data.humidity;
      document.getElementById('ph').innerText = data.ph;
      document.getElementById('ec').innerText = data.ec;
    });
}, 5000); // Update setiap 5 detik

// Mengirim perintah untuk mengontrol pompa/valve
function sendCommand(command) {
  fetch('/control?device=' + command).then((response) => {
    if (response.ok) {
      alert('Command sent: ' + command);
    } else {
      alert('Failed to send command');
    }
  });
}
